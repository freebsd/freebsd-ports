# New ports collection makefile for:	gkrellscore
# Date Created:				Fri Aug 17 15:57:42 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	gkrellscore
PORTVERSION=	0.0.2
PORTREVISION=	7
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.dvo.ru/pub/Gentoo/distfiles/ \
		http://voodoo.bawue.com/download/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plugin to GKrellM that displays current sports scores

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm \
		wget:${PORTSDIR}/ftp/wget

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
USE_PERL5_BUILD=yes
USE_GNOME=	imlib
USE_GMAKE=	yes

pre-patch:
	@${PERL} -pi.orig -e 's|/usr/bin/perl|${PERL}|; \
			s|(mkdir \$$dir)|$$1,0755|' \
		${WRKSRC}/gkrellscore.excite

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/gkrellscore.so \
		${PREFIX}/libexec/gkrellm/plugins
	@${INSTALL_SCRIPT} ${WRKSRC}/gkrellscore.excite \
		${PREFIX}/bin

.include <bsd.port.mk>
