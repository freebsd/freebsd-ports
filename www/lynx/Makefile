# New ports collection makefile for:    lynx
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	lynx
PORTVERSION=	2.8.4.1c
PORTREVISION=	0
CATEGORIES=	www ipv6
MASTER_SITES=	http://lynx.isc.org/current/
DISTNAME=	${PORTNAME}2.8.4rel.1

PATCH_SITES=	ftp://lynx.isc.org/lynx/lynx2.8.4/patches/
PATCHFILES=	lynx2.8.4rel.1a.patch \
		lynx2.8.4rel.1b.patch \
		lynx2.8.4rel.1c.patch

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A non-graphical, text-based World-Wide Web client

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}2-8-4
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-screen=ncurses --with-zlib --libdir="${L_LIB}" \
		--enable-nsl-fork --enable-persistent-cookies \
		--enable-ipv6
MAKE_ARGS=	helpdir=${L_HELP} docdir=${L_DOC}
MAKEFILE=	makefile
INSTALL_TARGET=	install-full
MAN1=		lynx.1

L_LIB=		${PREFIX}/etc
L_DOC=		${PREFIX}/share/doc/lynx
L_HELP=		${PREFIX}/share/lynx_help

post-patch:
	@${RM} -f ${WRKSRC}/CHANGES.orig

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${L_DOC}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${L_HELP}
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${L_LIB}/lynx.cfg

.include <bsd.port.mk>
