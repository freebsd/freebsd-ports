PORTNAME=	pimdd
PORTVERSION=	0.2.1.0
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://antc.uoregon.edu/PIMDM/
DISTNAME=	pimd-dense

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	UO Dense Protocol-Independent Multicast (PIM-DM) daemon for IPv4

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_RC_SUBR=	${PORTNAME}
CPPFLAGS+=	-D_PATH_PIMD_CONF=\\\"${PREFIX}/etc/pimd.conf\\\"
PLIST_FILES=	sbin/pimdd \
		etc/pimdd.conf.sample
PORTDOCS=	pimd-dense.html README CHANGES RELEASE.NOTES
OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pimdd ${STAGEDIR}${PREFIX}/sbin/pimdd
	${INSTALL_DATA} ${WRKSRC}/pimdd.conf \
	    ${STAGEDIR}${PREFIX}/etc/pimdd.conf.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
