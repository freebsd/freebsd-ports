# New ports collection makefile for:	gkrellscore
# Date Created:				Fri Aug 17 15:57:42 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	gkrellscore
PORTVERSION=	0.0.2
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://ssl.usu.edu/paul/gkrellscore/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	pat@FreeBSD.org
COMMENT=	Plugin to GKrellM that displays current sports scores

BUILD_DEPENDS=	${X11BASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm \
		wget:${PORTSDIR}/ftp/wget

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
USE_X_PREFIX=	yes
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
