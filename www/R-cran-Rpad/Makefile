# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Rpad
PORTVERSION=	1.3.0
PORTREVISION=	14
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Workbook-style, web-based interface to R

LICENSE=	GPLv2

USES=		cran:auto-plist shebangfix
SHEBANG_FILES=	inst/basehtml/editor/htmlarea/examples/*.cgi \
		inst/basehtml/editor/htmlarea/plugins/SpellChecker/spell-check-logic.cgi \
		inst/basehtml/server/*.pl \
		inst/serverversion/Statistics-R_perl_interface/script/*.pl

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|c:/apps/perl/bin/perl.exe|${perl_CMD}|' \
		${WRKSRC}/inst/basehtml/server/fileupload.pl
	@${RMDIR} ${WRKSRC}/inst/basehtml/editor/htmlarea/examples/test

.include <bsd.port.mk>
