# New ports collection makefile for:	clawsker
# Date created:		2008-02-04
# Whom:			Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	clawsker
PORTVERSION=	0.4.0
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/tools/

MAINTAINER=	c0rn@o2.pl
COMMENT=	Applet to edit Claws Mail's hidden preferences

RUN_DEPENDS=	claws-mail>=3.3.0:${PORTSDIR}/mail/claws-mail \
		${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/${PERL_ARCH}/Locale/gettext.pm:${PORTSDIR}/devel/p5-Locale-gettext

USE_PERL5=	5.8.0+
USE_GETTEXT=	yes

MAN1=		clawsker.1

PLIST_FILES=	bin/clawsker \
		share/locale/es/LC_MESSAGES/clawsker.mo \
		share/locale/sr/LC_MESSAGES/clawsker.mo \
		share/locale/sr@latin/LC_MESSAGES/clawsker.mo

.include <bsd.port.mk>
