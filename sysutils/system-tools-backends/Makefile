# New ports collection makefile for:	system-tools-backends
# Date created:				11 February 2005
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	system-tools-backends
PORTVERSION=	1.2.0
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.2
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Backend system admin scripts for gnome-system-tools

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
PREFIX?=	${X11BASE}
USE_GNOME=	gnomehack gnometarget intlhack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500800
RUN_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
.endif

.if ${PERL_LEVEL} < 500600
post-configure:
	@${FIND} ${WRKSRC} \( -name "*.pl" -or -name "*-conf" \) | \
		${XARGS} ${REINPLACE_CMD} -e 's|@scriptsdir|[@]scriptsdir|g'
.endif

.include <bsd.port.post.mk>
