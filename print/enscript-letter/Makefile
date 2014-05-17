# Created by: kline
# $FreeBSD$

PORTNAME=	enscript
PORTVERSION=	1.6.6
CATEGORIES+=	print
MASTER_SITES=	GNU
PKGNAMESUFFIX=	-${PAPERSIZE}
DISTNAME=	enscript-${PORTVERSION}

MAINTAINER?=	ports@FreeBSD.org
COMMENT=	ASCII to PostScript filter

USES=		shebangfix perl5
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls --with-media=${PS}
SHEBANG_FILES=	scripts/diffpp.in scripts/sliceprint.in
perl_OLD_CMD=	@PERLPROG@

CONFLICTS?=	enscript-a4-* enscript-letterdj-*

INFO=		enscript

PAPERSIZE?=	letter
PS?=		Letter

.if (${PAPERSIZE} != a4 && ${PAPERSIZE} != letter && ${PAPERSIZE} != letterdj)
.BEGIN:
	@${ECHO} "Error: invalid value for PAPERSIZE: \"${PAPERSIZE}\""
	@${ECHO} "Possible values are:  a4, letter, or letterdj"
	@${FALSE}
.endif

post-configure:
	${REINPLACE_CMD} -e 's|/usr/bin/perl|$${prefix}/bin/perl|g' ${WRKSRC}/scripts/Makefile

.include <bsd.port.mk>
