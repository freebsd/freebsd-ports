# ex:ts=8
# New ports collection makefile for:	rotix
# Date created:			Dec 8, 2001
# Whom:				lintux@debian.org
#
# $FreeBSD$
#

PORTNAME=	rotix
PORTVERSION=	0.8
CATEGORIES=	textproc
MASTER_SITES=	http://elektron.its.tudelft.nl/~hemmin98/

MAINTAINER=	lintux@debian.org

LIB_DEPENDS=	intl:${PORTSDIR}/devel/gettext

USE_GMAKE=	yes

MAN1=		rotix.1

post-patch:
	@${PERL} -pi -e "s,%%CFLAGS%%,${CFLAGS},g ; \
		s,%%LOCALBASE%%,${LOCALBASE},g ; \
		s,%%INSTALL_PROGRAM%%,${INSTALL_PROGRAM},g ; \
		s,%%INSTALL_MAN%%,${INSTALL_MAN},g ; \
		s,%%INSTALL_DATA%%,${INSTALL_DATA},g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
