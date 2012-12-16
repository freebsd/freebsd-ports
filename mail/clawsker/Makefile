# New ports collection makefile for:	clawsker
# Date created:		2008-02-04
# Whom:			Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	clawsker
PORTVERSION=	0.7.8
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/tools/

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Applet to edit Claws Mail's hidden preferences

LICENSE=	GPLv3

RUN_DEPENDS=	claws-mail>=3.8.1:${PORTSDIR}/mail/claws-mail \
		p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-Locale-gettext>=0:${PORTSDIR}/devel/p5-Locale-gettext

USE_PERL5=	yes

MAN1=		clawsker.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
EXTRA_PATCHES=	${FILESDIR}/extra-Makefile-without_nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
