# ex:ts=8
# New ports collection makefile for:	gxmlviewer
# Date created:			Nov 8, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gxmlviewer
PORTVERSION=	1.3.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext \
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_GNOME=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${PERL} -pi -e "s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure

.include <bsd.port.mk>
