# New ports collection makefile for:	tvark
# Date created:		19 July 2001
# Whom:			mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	tvark
PORTVERSION=	0.4
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://voodoo.bawue.com/download/ \
		http://www.tvark.com/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI network monitoring tool, tied to a MySQL database

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_PERL5_BUILD=yes
USE_GNOME=	gtk12
USE_MYSQL=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -E -e "s|^(LDFLAGS.*)/usr/local|\1${LOCALBASE}|" \
		-e "s|/usr/local/bin|${PREFIX}/bin|" \
		-e "s|gtk-config|${GTK_CONFIG}|g" \
		-e "s|-ggdb|${CFLAGS}|" \
		${WRKSRC}/Makefile

.include <bsd.port.post.mk>
