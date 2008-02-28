# New ports collection makefile for:	claws-mail-spamreport
# Date created:		06 April 2007
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spamreport
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-
DISTNAME=	spam_report-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	SpamReport plugin for claws-mail

LIB_DEPENDS=	curl.4:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	claws-mail>=3.3.1:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=3.3.1:${PORTSDIR}/mail/claws-mail

USE_GMAKE=	yes
USE_XLIB=	yes
USE_AUTOTOOLS=	autoconf:261
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE}

PLIST_FILES=lib/claws-mail/plugins/spamreport.a \
	    lib/claws-mail/plugins/spamreport.la \
	    lib/claws-mail/plugins/spamreport.so \
	    share/locale/ca/LC_MESSAGES/spam_report.mo \
	    share/locale/fi/LC_MESSAGES/spam_report.mo \
	    share/locale/es/LC_MESSAGES/spam_report.mo \
	    share/locale/fr/LC_MESSAGES/spam_report.mo \
	    share/locale/hu/LC_MESSAGES/spam_report.mo \
	    share/locale/pt_BR/LC_MESSAGES/spam_report.mo \
	    share/locale/sk/LC_MESSAGES/spam_report.mo \
	    share/locale/it/LC_MESSAGES/spam_report.mo

.include <bsd.port.mk>
