PORTNAME=	fcheck
PORTVERSION=	2.07.59
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.sourcefiles.org/Networking/Security/Intrusion_Detection/ \
		http://bsd-geek.de/FreeBSD/distfiles/
DISTNAME=	FCheck_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Intrusion detection and Policy enforcement / auditing software

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

WRKSRC=	${WRKDIR}/${PORTNAME}

NO_BUILD=	YES
USES=		perl5 shebangfix dos2unix

SHEBANG_FILES=	${WRKSRC}/${PORTNAME}
DOS2UNIX_FILES=	${WRKSRC}/${PORTNAME}.cfg

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/admtools/conf/|${PREFIX}/etc/|' \
		${WRKSRC}/${PORTNAME}
	@${REINPLACE_CMD} -e 's|/usr/local/admtools/|/var/${PORTNAME}/|' \
		-e 's|/bin/file|/usr/bin/file|' -e 's|/bin/cksum|/sbin/sha512|' \
		${WRKSRC}/${PORTNAME}.cfg

do-install:
	${MKDIR} ${STAGEDIR}/var/${PORTNAME}/logs
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.cfg ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.cfg.sample
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/install ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
