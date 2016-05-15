# Created by: Yonatan <onatan@gmail.com>
# $FreeBSD$

PORTNAME=	metasploit
PORTVERSION=	4.12.1
CATEGORIES=	security

MAINTAINER=	tanawts@gmail.com
COMMENT=	Exploit-Framework for Penetration-Testing

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	nasm:devel/nasm \
		nmap:security/nmap \
		rubygem-activerecord4>=4.2.6:databases/rubygem-activerecord4 \
		rubygem-activesupport4>=4.2.6:devel/rubygem-activesupport4 \
		rubygem-actionpack4>=4.2.6:www/rubygem-actionpack4 \
		rubygem-bcrypt>=0:security/rubygem-bcrypt \
		rubygem-bundler>=0:sysutils/rubygem-bundler \
		rubygem-jsobfu>=0.2.0:www/rubygem-jsobfu \
		rubygem-json>=0:devel/rubygem-json \
		rubygem-metasm>=0:devel/rubygem-metasm \
		rubygem-metasploit-concern>=2.0.1:security/rubygem-metasploit-concern \
		rubygem-metasploit-credential>=0.14.5:security/rubygem-metasploit-credential \
		rubygem-metasploit_data_models>=0.24.0,2:security/rubygem-metasploit_data_models \
		rubygem-metasploit-model>=0.29.0:security/rubygem-metasploit-model \
		rubygem-metasploit-payloads>=0.0.3:security/rubygem-metasploit-payloads \
		rubygem-msgpack>=0:devel/rubygem-msgpack \
		rubygem-network_interface>=0.0.1:net/rubygem-network_interface \
		rubygem-nokogiri>=0:textproc/rubygem-nokogiri \
		rubygem-packetfu>=1.1.9:net/rubygem-packetfu \
		rubygem-pcaprub>=0:net/rubygem-pcaprub \
		rubygem-pg>=0.11:databases/rubygem-pg \
		rubygem-railties4>=4.2.6:www/rubygem-railties4 \
		rubygem-recog>=1.0:security/rubygem-recog \
		rubygem-openssl-ccm>=0:security/rubygem-openssl-ccm \
		rubygem-octokit>=0:net/rubygem-octokit \
		rubygem-redcarpet>=0:textproc/rubygem-redcarpet \
		rubygem-patch_finder>=0:devel/rubygem-patch_finder \
		rubygem-robots>=0:www/rubygem-robots \
		rubygem-rubyzip>=1.1:archivers/rubygem-rubyzip \
		rubygem-sqlite3>=0:databases/rubygem-sqlite3 \
		rubygem-tzinfo>=0:devel/rubygem-tzinfo \
		rubygem-filesize>=0:devel/rubygem-filesize

SCRIPTS=	msfbinscan msfconsole msfd msfelfscan \
		msfmachscan msfpescan msfrop msfrpc msfrpcd msfvenom

USE_GITHUB=	yes
GH_ACCOUNT=	rapid7
GH_PROJECT=	metasploit-framework

USES=		ncurses:port
USE_RUBY=	yes

post-patch:
	${REINPLACE_CMD} 's,git ls-files,find . ! -type d | sed "s|^./||", ; \
		/rb-readline-r7/d' ${WRKSRC}/metasploit-framework.gemspec

do-build:
	${RM} ${WRKSRC}/Gemfile.lock
	${MKDIR} ${WRKSRC}/log
	${TOUCH} ${WRKSRC}/Gemfile.lock ${WRKSRC}/log/production.log
	${CHMOD} 666 ${WRKSRC}/Gemfile.lock ${WRKSRC}/log/production.log
	${REINPLACE_CMD} '/^group :coverage/,/^end/d ; /^group :development/,/^end/d ; /^group :test/,/^end/d' \
		${WRKSRC}/Gemfile

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${PAX} -rw . ${STAGEDIR}${DATADIR}
.for f in ${SCRIPTS}
	${PRINTF} '#!/bin/sh\ncd ${DATADIR} && ./${f} "$$@"\n' > ${STAGEDIR}${PREFIX}/bin/${f}
	${CHMOD} ${BINMODE} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor

post-install:
.for f in ${SCRIPTS}
	@${ECHO} "bin/${f}" >> ${TMPPLIST}
.endfor
	@${FIND} ${STAGEDIR}${DATADIR} ! -type d | \
		${SED} 's,${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} -ds ${STAGEDIR}${DATADIR} -type d -empty | \
		${SED} 's,${STAGEDIR}${PREFIX}/,, ; s,^,@dir ,' >> ${TMPPLIST}

.include <bsd.port.mk>
