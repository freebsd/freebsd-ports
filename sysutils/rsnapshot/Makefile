# New ports collection makefile for:	rsnapshot
# Date created:		2004-01-03
# Whom:			Ralf van Dooren <r.vdooren@snow.nl>
#
# $FreeBSD$
#

PORTNAME=	rsnapshot
PORTVERSION=	1.1.7
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rsnapshot.org/downloads/

MAINTAINER=	r.vdooren@snow.nl
COMMENT=	Filesystem snapshot utility based on rsync(1)

BUILD_DEPENDS=	rsync:${PORTSDIR}/net/rsync
RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		rsnapshot.1
DOCS=		AUTHORS ChangeLog README TODO

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
