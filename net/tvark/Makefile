# New ports collection makefile for:	tvark
# Date created:		19 July 2001
# Whom:			mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	tvark
PORTVERSION=	0.3
CATEGORIES=	net
MASTER_SITES=	http://www.tvark.com/

MAINTAINER=	mwest@uct.ac.za

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client

USE_X_PREFIX=	yes
USE_GTK=	yes

post-patch:
	@${PERL} -pi -e "s|/usr/local/bin|${PREFIX}/bin|" ${WRKSRC}/Makefile
	@${PERL} -pi -e "s|gtk-config|${GTK_CONFIG}|" ${WRKSRC}/Makefile
	@${PERL} -pi -e "s|-ggdb|${CFLAGS}|" ${WRKSRC}/Makefile

.include <bsd.port.mk>
