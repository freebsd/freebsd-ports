# Created by: Yonatan <onatan@gmail.com>
# $FreeBSD$

PORTNAME=	metasploit
DISTVERSION=	4.7.2
CATEGORIES=	security
MASTER_SITES=	http://downloads.metasploit.com/data/releases/archive/
DISTNAME=	framework-${DISTVERSION}

MAINTAINER=	tanawts@gmail.com
COMMENT=	Exploit-Framework for Penetration-Testing

RUN_DEPENDS=	nasm:${PORTSDIR}/devel/nasm \
		nmap:${PORTSDIR}/security/nmap \
		rubygem-activesupport>=3.0.0:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-json>=0:${PORTSDIR}/devel/rubygem-json \
		rubygem-msgpack>=0:${PORTSDIR}/devel/rubygem-msgpack \
		rubygem-nokogiri>=0:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-network_interface>=0.0.1:${PORTSDIR}/net/rubygem-network_interface \
		rubygem-packetfu>=1.1.8:${PORTSDIR}/net/rubygem-packetfu \
		rubygem-pcaprub>=0:${PORTSDIR}/net/rubygem-pcaprub \
		rubygem-robots>=0:${PORTSDIR}/www/rubygem-robots

WRKSRC=		${WRKDIR}/msf3
SCRIPTS=	msfbinscan msfcli msfconsole msfd msfelfscan msfencode \
		msfmachscan msfpayload msfpescan msfrop msfrpc msfrpcd msfvenom

NO_BUILD=	yes
USES=		ncurses:port
USE_RUBY=	yes
USE_RUBY_FEATURES=	iconv
USE_BZIP2=	yes

OPTIONS_DEFINE=	DB
OPTIONS_DEFAULT=DB
DB_DESC=	Database support

DB_RUN_DEPENDS=	rubygem-activerecord>=0:${PORTSDIR}/databases/rubygem-activerecord \
		rubygem-metasploit_data_models>=0.15.1:${PORTSDIR}/security/rubygem-metasploit_data_models \
		rubygem-pg>=0.11:${PORTSDIR}/databases/rubygem-pg

post-patch:
	${REINPLACE_CMD} 's|bundler/setup|rubygems|' ${WRKSRC}/lib/msfenv.rb

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -Rp ${WRKSRC}/ ${STAGEDIR}${DATADIR}
.for f in ${SCRIPTS}
	${LN} -s ${DATADIR}/${f} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor

post-install:
.for f in ${SCRIPTS}
	${ECHO} "bin/${f}" >> ${TMPPLIST}
.endfor
	@${FIND} ${STAGEDIR}${DATADIR} -type f | ${SED} 's,${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${DATADIR} -type l | ${SED} 's,${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,${STAGEDIR}${PREFIX}/,, ; s,^,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
