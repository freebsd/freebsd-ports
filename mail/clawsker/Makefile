# New ports collection makefile for:	clawsker
# Date created:		2008-02-04
# Whom:			Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	clawsker
PORTVERSION=	0.7.1
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/tools/

MAINTAINER=	c0rn@o2.pl
COMMENT=	Applet to edit Claws Mail's hidden preferences

RUN_DEPENDS=	claws-mail>=3.7.6:${PORTSDIR}/mail/claws-mail \
		${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/${PERL_ARCH}/Locale/gettext.pm:${PORTSDIR}/devel/p5-Locale-gettext

USE_PERL5=	5.8.0+

MAN1=		clawsker.1

.if defined(WITHOUT_NLS)
EXTRA_PATCHES=	${FILESDIR}/extra-Makefile-without_nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
