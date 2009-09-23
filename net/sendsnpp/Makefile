# New ports collection makefile for:	net/sendsnpp
# Date created:				2005-12-17
# Whom:			Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
#
# $FreeBSD$
# $Tecnik: ports/net/sendsnpp/Makefile,v 1.4 2006/06/11 20:04:50 itetcu Exp $

PORTNAME=	sendSNPP
DISTVERSION=	v1.03
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	http://caspian.dotconf.net/menu/Software/SendSNPP/ \
		http://T32.TecNik93.com/FreeBSD/ports/${PORTNAME}/sources/

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Tool for sending messages through a RFC1861 compliant SNPP server

NO_BUILD=	yes
USE_PERL5_RUN=	yes

PLIST_FILES=	bin/sendSNPP.pl

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|g' ${WRKSRC}/${PORTNAME}.pl

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${PORTNAME}.pl ${PREFIX}/bin

.include <bsd.port.mk>
