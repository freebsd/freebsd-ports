# New ports collection makefile for:	ntimelord
# Date created:		29 Oct 1997
# Whom:			Takeru NAIKI <naiki@bfd.es.hokudai.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	ntimelord
PORTVERSION=	1.0
CATEGORIES=	net
MASTER_SITES=	ftp://terminator.rs.itd.umich.edu/unix/netatalk/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	naiki@bfd.es.hokudai.ac.jp

RUN_DEPENDS=	${LOCALBASE}/libexec/atalkd:${PORTSDIR}/net/netatalk

post-install:
	@$(ECHO_MSG) "============================================================"
	@$(ECHO_MSG) " You must edit the file netatalk.sh installed with netatalk"
	@$(ECHO_MSG) " to start timelord automatically at boot-time."
	@$(ECHO_MSG) " "
	@$(ECHO_MSG) " Client program tardis can find in timelord.1.4.shar.Z"
	@$(ECHO_MSG) " which is in ftp://munnari.OZ.AU/mac/"
	@$(ECHO_MSG) "============================================================"

.include <bsd.port.mk>
