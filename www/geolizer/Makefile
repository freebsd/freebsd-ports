# New ports collection makefile for:    geolizer
# Date created:         23 July 2004
# Whom:                 ache@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	geolizer
PORTVERSION=	2.1.10
PORTREVISION=	1
CATEGORIES+=	www
MASTER_SITES=	ftp://ftp.mrunix.net/pub/webalizer/:main \
		ftp://ftp.dinoex.de/pub/FreeBSD/distfiles/:main \
		http://sysd.org/proj/:geo
DISTNAME=       webalizer-2.01-10-src
DISTFILES=	${DISTNAME}.tar.bz2:main \
		geolizer_2.01-10-patch.20040216.tar.bz2:geo
EXTRA_PATCHES=	${WRKDIR}/geolizer_2.01-10-patch/geolizer.patch
PATCH_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A web server log file analysis program, using GeoIP library

LIB_DEPENDS=    png.5:${PORTSDIR}/graphics/png \
		gd.4:${PORTSDIR}/${GD_PORT} \
		GeoIP.4:${PORTSDIR}/net/GeoIP

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
DOCSDIR?=	${PREFIX}/share/doc/${PKGNAMEPREFIX}webalizer
EXAMPLESDIR?=	${PREFIX}/share/examples/${PKGNAMEPREFIX}webalizer
GD_PORT?=	graphics/gd

CONFLICTS=	webalizer-2*

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--enable-dns \
			--with-etcdir=${PREFIX}/etc \
			--with-gdlib=${LOCALBASE}/lib \
			--with-gd=${LOCALBASE}/include \
			--enable-geoip \
			--with-geoip-lib=${LOCALBASE}/lib \
			--with-geoip-inc=${LOCALBASE}/include \
			--with-png=${LOCALBASE}/lib \
			--with-png-inc=${LOCALBASE}/include \
			--with-language=english

CFLAGS+=	-DLINKLIST_MAX_STRING=256
MAN1=		${PKGNAMEPREFIX}webalizer.1
DOC1=		CHANGES Copyright INSTALL \
		README README.FIRST DNS.README country-codes.txt
DOC2=		INSTALL GeoIP.README
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src$//}
PLIST_SUB+=	PKGNAMEPREFIX=${PKGNAMEPREFIX}

pre-configure:
	@${MV} ${WRKSRC}/webalizer.1 ${WRKSRC}/webalizer.1.sed
	${SED} -e "s=/etc=${PREFIX}/etc=" \
		${WRKSRC}/webalizer.1.sed > ${WRKSRC}/webalizer.1
	@${MV} ${WRKSRC}/webalizer.c ${WRKSRC}/webalizer.c.sed
	${SED} -e "s=webalizer.conf=${PKGNAMEPREFIX}webalizer.conf=" \
		${WRKSRC}/webalizer.c.sed > ${WRKSRC}/webalizer.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/webalizer \
		${PREFIX}/bin/${PKGNAMEPREFIX}webalizer
	${LN} -sf ${PKGNAMEPREFIX}webalizer \
		${PREFIX}/bin/${PKGNAMEPREFIX}webazolver
	${INSTALL_DATA} ${WRKSRC}/sample.conf \
		${PREFIX}/etc/${PKGNAMEPREFIX}webalizer.conf-dist ;

post-install:
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/webalizer.1 ${PREFIX}/man/man1/${i}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/geolizer
.for i in ${DOC1}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/${i}
.endfor
.for i in ${DOC2}
	@${INSTALL_DATA} ${WRKDIR}/geolizer_2.01-10-patch/${i} \
		${DOCSDIR}/geolizer/${i}
.endfor
	${MKDIR} ${EXAMPLESDIR}
.for i in msfree.png sample.conf webalizer.png
	@${INSTALL_DATA} ${WRKSRC}/${i} ${EXAMPLESDIR}/${i}
.endfor
.endif

.include <bsd.port.post.mk>
