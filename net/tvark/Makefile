# New ports collection makefile for:	tvark
# Date created:		19 July 2001
# Whom:			mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	tvark
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.tvark.com/

MAINTAINER=	mwest@uct.ac.za
COMMENT=	GUI network monitoring tool, tied to a MySQL database

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client

USE_X_PREFIX=	yes
USE_PERL5_BUILD=yes
USE_GNOME=	gtk12

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile"
.endif

post-patch:
	@${PERL} -pi -e "s|/usr/local/bin|${PREFIX}/bin|" ${WRKSRC}/Makefile
	@${PERL} -pi -e "s|gtk-config|${GTK_CONFIG}|" ${WRKSRC}/Makefile
	@${PERL} -pi -e "s|-ggdb|${CFLAGS}|" ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
