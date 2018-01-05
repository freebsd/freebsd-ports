# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	jmba
PORTVERSION=	0.5.5
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Junk Mail Buffering Agent

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_func_gettext=no ac_cv_lib_intl_main=no
USES=	gmake tar:bzip2

PLIST_FILES=	bin/jmba \
		man/man1/jmba.1.gz

.include <bsd.port.mk>
