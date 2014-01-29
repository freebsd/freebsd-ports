# Created by: Ryan T. Dean <rtdean@cytherianage.net>
# $FreeBSD$

PORTNAME=	ljdeps
PORTVERSION=	1.0
PORTREVISION=	6
CATEGORIES=	www perl5
MASTER_SITES=	# Undefined
DISTFILES=	# Undefined

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A meta-port to install all the perl modules used by LiveJournal

RUN_DEPENDS=	p5-Net-Telnet>=0:${PORTSDIR}/net/p5-Net-Telnet \
		p5-Image-Size>=0:${PORTSDIR}/graphics/p5-Image-Size \
		p5-MIME-Tools>=0:${PORTSDIR}/mail/p5-MIME-Tools \
		p5-MIME-Lite>=0:${PORTSDIR}/mail/p5-MIME-Lite \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-HTML-Tagset>=0:${PORTSDIR}/www/p5-HTML-Tagset \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Time-modules>=0:${PORTSDIR}/devel/p5-Time-modules \
		p5-GD>=0:${PORTSDIR}/graphics/p5-GD \
		p5-GD-Graph>=0:${PORTSDIR}/graphics/p5-GD-Graph \
		p5-GD-TextUtil>=0:${PORTSDIR}/graphics/p5-GD-TextUtil \
		p5-Data-ShowTable>=0:${PORTSDIR}/devel/p5-Data-ShowTable \
		p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql \
		p5-Proc-ProcessTable>=0:${PORTSDIR}/devel/p5-Proc-ProcessTable \
		p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite \
		p5-Unicode-MapUTF8>=0:${PORTSDIR}/converters/p5-Unicode-MapUTF8

EXTRACT_ONLY=	# Empty
NO_BUILD=	yes
USES=		perl5

do-install:	# Empty

.include <bsd.port.mk>
