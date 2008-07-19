# New ports collection makefile for:	msort
# Date created:		2006-08-11
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	msort
PORTVERSION=	8.47
CATEGORIES=	textproc
MASTER_SITES=	http://billposer.org/Software/Downloads/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Sorting files in sophisticated ways

LIB_DEPENDS=	tre:${PORTSDIR}/textproc/libtre \
    		uninum:${PORTSDIR}/devel/libuninum \
		utf8proc:${PORTSDIR}/textproc/utf8proc
RUN_DEPENDS=	iwidgets>=0:${PORTSDIR}/x11-toolkits/iwidgets

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include"
MAKE_ENV+=	INCLUDES="-I${LOCALBASE}/include"
GNU_CONFIGURE=	yes
USE_TK_RUN=	yes
USE_TCL_WRAPPER=	yes
USE_GETTEXT=	yes

PLIST_FILES=	bin/msg bin/msort

MAN1=		msort.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
BROKEN=		Does not build with older versions of FreeBSD
.endif

.include <bsd.port.post.mk>
