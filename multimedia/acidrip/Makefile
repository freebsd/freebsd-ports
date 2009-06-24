# New ports collection makefile for:	acidrip
# Date created:		2004-03-31
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	acidrip
PORTVERSION=	0.14
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	SFE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK2::Perl wrapper for MPlayer and MEncoder for ripping DVDs

BUILD_DEPENDS=	lsdvd:${PORTSDIR}/multimedia/lsdvd \
		mencoder:${PORTSDIR}/multimedia/mencoder \
		${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MAN1=		acidrip.1

.if defined(WITH_DVD_DEVICE)
DEFAULT_DVD_DEVICE=${WITH_DVD_DEVICE}
.else
DEFAULT_DVD_DEVICE=/dev/acd0
.endif

pre-everything::
.if !defined(WITH_DVD_DEVICE)
	@${ECHO_MSG} "===> The default DVD device is ${DEFAULT_DVD_DEVICE}"
	@${ECHO_MSG} "===> Define WITH_DVD_DEVICE if you want to change the default"
	@${ECHO_MSG} "===> For example, 'make WITH_DVD_DEVICE=\"/dev/somedevice\"'"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/dev/dvd|${DEFAULT_DVD_DEVICE}|' ${WRKSRC}/AcidRip/acidrip.pm
	@${RM} ${WRKSRC}/AcidRip/*.bak
	@${RM} ${WRKSRC}/AcidRip/*.orig

.include <bsd.port.mk>
