# Created by: Radim Kolar
# $FreeBSD$

PORTNAME=	rkhunter
PORTVERSION=	1.4.2
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	lukasz@wasikowski.net
COMMENT=	Rootkit detection tool

LICENSE=	GPLv2

OPTIONS_DEFINE=	LSOF NMAP DOCS
OPTIONS_DEFAULT=LSOF

RUN_DEPENDS+=	p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		${LOCALBASE}/bin/wget:ftp/wget

USES=		perl5 shebangfix
SHEBANG_FILES=	files/check_modules.pl files/filehashsha.pl \
		files/stat.pl
NO_BUILD=	yes
SUB_FILES=	415.${PORTNAME}

PORTDOCS=	ACKNOWLEDGMENTS CHANGELOG FAQ LICENSE README

LSOF_RUN_DEPENDS=	lsof:sysutils/lsof
NMAP_RUN_DEPENDS=	nmap:security/nmap

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|{SHAREDIR}/man/man8|{PREFIX}/man/man8|g' \
		${WRKSRC}/installer.sh
	@${REINPLACE_CMD} -i '' -e 's|RKHPREFIX|${PREFIX}|g' \
		${WRKSRC}/files/${PORTNAME}.conf

do-install:
	cd ${WRKSRC} && ./installer.sh --layout custom ${STAGEDIR}${PREFIX} --install
	${INSTALL_MAN} ${WRKSRC}/files/${PORTNAME}.8 \
		${STAGEDIR}${MAN8PREFIX}/man/man8
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/security
	${INSTALL_SCRIPT} ${WRKDIR}/415.${PORTNAME} ${STAGEDIR}${PREFIX}/etc/periodic/security
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/files/|} ${STAGEDIR}${DOCSDIR}

post-install:
	@${REINPLACE_CMD} -i '' -e 's|${STAGEDIR}||g' \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf
	${INSTALL_DATA} ${WRKSRC}/files/${PORTNAME}.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample
	${INSTALL_DATA} -m 640 ${WRKSRC}/files/programs_bad.dat ${STAGEDIR}${PREFIX}/var/lib/${PORTNAME}/db/programs_bad.dat.sample
	${INSTALL_DATA} -m 640 ${WRKSRC}/files/mirrors.dat ${STAGEDIR}${PREFIX}/var/lib/${PORTNAME}/db/mirrors.dat.sample

.include <bsd.port.mk>
