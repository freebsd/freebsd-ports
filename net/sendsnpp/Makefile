# Created by: Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
# $FreeBSD$

PORTNAME=	sendSNPP
DISTVERSION=	v1.03
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	http://caspian.dotconf.net/menu/Software/SendSNPP/ \
		http://T32.TecNik93.com/FreeBSD/ports/${PORTNAME}/sources/

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Tool for sending messages through a RFC1861 compliant SNPP server

NO_BUILD=	yes
USES=		perl5
USE_PERL5=	run

PLIST_FILES=	bin/sendSNPP.pl

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|g' ${WRKSRC}/${PORTNAME}.pl

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${PORTNAME}.pl ${PREFIX}/bin

.include <bsd.port.mk>
