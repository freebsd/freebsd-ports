# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pimdd
PORTVERSION=	0.2.1.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://antc.uoregon.edu/PIMDM/
DISTNAME=	pimd-dense

MAINTAINER=	ports@FreeBSD.org
COMMENT=	UO Dense Protocol-Independent Multicast (PIM-DM) daemon for IPv4

MAKE_ARGS+=	CC="${CC}"

NO_MAN=	yes

PLIST_FILES=	sbin/pimdd \
		etc/pimdd.conf.sample

PORTDOCS=	pimd-dense.html README CHANGES RELEASE.NOTES

OPTIONS_DEFINE=	DOCS

EXTRA_PATCHES=	${FILESDIR}/extra-patch-defs.h

post-patch:
	${REINPLACE_CMD} -e 's|/etc/pimd.conf|${PREFIX}/etc/pimd.conf|g' ${WRKSRC}/pathnames.h
	${REINPLACE_CMD} -e 's|-Wall -g|${CFLAGS}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pimdd ${STAGEDIR}${PREFIX}/sbin/pimdd
	${INSTALL_DATA} ${WRKSRC}/pimdd.conf ${STAGEDIR}${PREFIX}/etc/pimdd.conf.sample
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
