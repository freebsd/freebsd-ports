# New ports collection makefile for:	scrollkeeper
# Date created:				6 April 2001
# Whom:					Rene Hexel <rh@netbsd.org>
#
# $FreeBSD$
#

PORTNAME=	scrollkeeper
PORTVERSION=	0.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_GNOME:S,%SUBDIR%,stable/sources/scrollkeeper,}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	xml.5:${PORTSDIR}/textproc/libxml \
		intl.1:${PORTSDIR}/devel/gettext

INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--localstatedir=/var
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"

MAN8=		scrollkeeper-config.8 scrollkeeper-preinstall.8 \
		scrollkeeper-rebuilddb.8 scrollkeeper-update.8

pre-patch:
	@find ${WRKSRC} -name Makefile.in | xargs ${PERL} -pi -e   \
		's|\$$\(LN_S\) -f -n|\$$\(LN_S\) -f|g'

.include <bsd.port.mk>
