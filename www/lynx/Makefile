# New ports collection makefile for:    lynx
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	lynx
PORTVERSION=	2.8.5
PORTREVISION=	2
CATEGORIES=	www ipv6
MASTER_SITES=	http://lynx.isc.org/current/ \
		ftp://lynx.isc.org/lynx2.8.5/patches/:patches
DISTNAME=	${PORTNAME}2.8.5rel.1

PATCH_SITES=	ftp://lynx.isc.org/lynx2.8.5/patches/
.for i in 2 3 4
PATCHFILES+=	2.8.5rel.${i}.patch.gz
.endfor
PATCH_DIST_STRIP=	-p1

MAINTAINER?=	jharris@widomaker.com
COMMENT?=	A non-graphical, text-based World-Wide Web client

CONFLICTS?=	lynx-ssl* lynx-current*

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}2-8-5
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-screen=ncurses --with-zlib --libdir="${L_LIB}" \
		--enable-nsl-fork --enable-persistent-cookies \
		--enable-ipv6

.if defined(ENABLE_DEFAULT_COLORS)
CONFIGURE_ARGS+=--enable-default-colors
.endif

MAKE_ARGS=	helpdir=${L_HELP} docdir=${DOCSDIR}
MAKEFILE=	makefile
INSTALL_TARGET=	install-full
MAN1=		lynx.1

L_LIB=		${PREFIX}/etc
L_HELP=		${PREFIX}/share/lynx_help

post-patch:
	@${RM} -f ${WRKSRC}/CHANGES.orig
	@${REINPLACE_CMD} -e 's|-lssl -lcrypto|-L${OPENSSLLIB} &|g' \
		${WRKSRC}/configure

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${L_HELP}
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${L_LIB}/lynx.cfg

.include <bsd.port.mk>
