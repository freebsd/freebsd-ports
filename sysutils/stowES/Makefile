# ex:ts=8
# New ports collection makefile for:	stowES
# Date created:			Mar 17, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	stowES
PORTVERSION=	0.4.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.inf.tu-dresden.de/~al10/stowES/download/

MAINTAINER=	ijliao@FreeBSD.org

#RUN_DEPENDS=	bzip2:${PORTSDIR}/archivers/bzip2 \
#		stow:${PORTSDIR}/sysutils/stow

GNU_CONFIGURE=	yes

USE_GMAKE=	yes

MAN1=	stowES.1

post-patch:
.for file in stowES.in stowES.pod
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
