# Created by: Yonatan <onatan@gmail.com>
# $FreeBSD$

PORTNAME=	metasploit
PORTVERSION=	4.11.2
CATEGORIES=	security

MAINTAINER=	tanawts@gmail.com
COMMENT=	Exploit-Framework for Penetration-Testing

RUN_DEPENDS=	nasm:${PORTSDIR}/devel/nasm \
		nmap:${PORTSDIR}/security/nmap \
		rubygem-activesupport>=3.0.0:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-actionpack>=0:${PORTSDIR}/www/rubygem-actionpack \
		rubygem-bcrypt>=0:${PORTSDIR}/security/rubygem-bcrypt \
		rubygem-bundler>=0:${PORTSDIR}/sysutils/rubygem-bundler \
		rubygem-jsobfu>=0.2.0:${PORTSDIR}/www/rubygem-jsobfu \
		rubygem-json>=0:${PORTSDIR}/devel/rubygem-json \
		rubygem-metasploit-concern>=0.4.0:${PORTSDIR}/security/rubygem-metasploit-concern \
		rubygem-metasploit-model>=0.29.0:${PORTSDIR}/security/rubygem-metasploit-model \
		rubygem-metasploit-payloads>=0.0.3:${PORTSDIR}/security/rubygem-metasploit-payloads \
		rubygem-msgpack>=0:${PORTSDIR}/devel/rubygem-msgpack \
		rubygem-nokogiri>=0:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-network_interface>=0.0.1:${PORTSDIR}/net/rubygem-network_interface \
		rubygem-packetfu>=1.1.9:${PORTSDIR}/net/rubygem-packetfu \
		rubygem-pcaprub>=0:${PORTSDIR}/net/rubygem-pcaprub \
		rubygem-railties>=3.0.0:${PORTSDIR}/www/rubygem-railties \
		rubygem-recog>=1.0:${PORTSDIR}/security/rubygem-recog \
		rubygem-robots>=0:${PORTSDIR}/www/rubygem-robots \
		rubygem-rubyzip>=1.1:${PORTSDIR}/archivers/rubygem-rubyzip \
		rubygem-sqlite3>=0:${PORTSDIR}/databases/rubygem-sqlite3 \
		rubygem-tzinfo03>=0:${PORTSDIR}/devel/rubygem-tzinfo03

SCRIPTS=	msfbinscan msfcli msfconsole msfd msfelfscan msfencode \
		msfmachscan msfpayload msfpescan msfrop msfrpc msfrpcd msfvenom

USE_GITHUB=	yes
GH_ACCOUNT=	rapid7
GH_PROJECT=	metasploit-framework

USES=		ncurses:port
USE_RUBY=	yes

OPTIONS_DEFINE=	DB
OPTIONS_DEFAULT=DB
DB_DESC=	Database support

DB_RUN_DEPENDS=	rubygem-activerecord>=3.0.0:${PORTSDIR}/databases/rubygem-activerecord \
		rubygem-metasploit-credential>=0.14.5:${PORTSDIR}/security/rubygem-metasploit-credential \
		rubygem-metasploit_data_models>=0.24.0,2:${PORTSDIR}/security/rubygem-metasploit_data_models \
		rubygem-pg>=0.11:${PORTSDIR}/databases/rubygem-pg

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} 's,git ls-files,find . ! -type d | sed "s|^./||", ; \
		/packetfu/s/1.1.9/>= 1.1.9/ ; \
		/rb-readline/d' ${WRKSRC}/metasploit-framework.gemspec

do-build:
	${RM} ${WRKSRC}/Gemfile.lock
	${MKDIR} ${WRKSRC}/log
	${TOUCH} ${WRKSRC}/Gemfile.lock ${WRKSRC}/log/production.log
	${CHMOD} 666 ${WRKSRC}/Gemfile.lock ${WRKSRC}/log/production.log
	${REINPLACE_CMD} '/^group :coverage/,/^end/d ; /^group :development/,/^end/d ; /^group :test/,/^end/d' \
		${WRKSRC}/Gemfile
.if ! ${PORT_OPTIONS:MDB}
	${REINPLACE_CMD} '/^group :db do/,/^end/d' ${WRKSRC}/Gemfile
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -Rp ${WRKSRC}/ ${STAGEDIR}${DATADIR}
.for f in ${SCRIPTS}
	${PRINTF} '#!/bin/sh\ncd ${DATADIR} && ./${f} "$$@"\n' > ${STAGEDIR}${PREFIX}/bin/${f}
	${CHMOD} ${BINMODE} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor

post-install:
.for f in ${SCRIPTS}
	${ECHO} "bin/${f}" >> ${TMPPLIST}
.endfor
	@${FIND} ${STAGEDIR}${DATADIR} ! -type d | \
		${SED} 's,${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} -ds ${STAGEDIR}${DATADIR} -type d -empty | \
		${SED} 's,${STAGEDIR}${PREFIX}/,, ; s,^,@dir ,' >> ${TMPPLIST}

.include <bsd.port.mk>
