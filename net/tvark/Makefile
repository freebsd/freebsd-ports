# New ports collection makefile for:	tvark
# Date created:		19 July 2001
# Whom:			mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	tvark
PORTVERSION=	0.4
CATEGORIES=	net
MASTER_SITES=	http://voodoo.oberon.net/download/ \
		http://www.tvark.com/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI network monitoring tool, tied to a MySQL database

USE_X_PREFIX=	yes
USE_PERL5_BUILD=yes
USE_GNOME=	gtk12
USE_MYSQL=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${PERL} -pi -e "s|/usr/local/bin|${PREFIX}/bin|" ${WRKSRC}/Makefile
	@${PERL} -pi -e "s|gtk-config|${GTK_CONFIG}|" ${WRKSRC}/Makefile
	@${PERL} -pi -e "s|-ggdb|${CFLAGS}|" ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
