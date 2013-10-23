# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ssh-copy-id
PORTVERSION=	5.6p1
CATEGORIES=	security
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Small script which copies your ssh public-key to a remote host

NO_BUILD=	yes

PLIST_FILES=	bin/ssh-copy-id man/man1/ssh-copy-id.1.gz

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 1000024
IGNORE=		is already in the base system
.endif

pre-patch:
.for f in ssh-copy-id ssh-copy-id.1
	@${CP} ${FILESDIR}/${f} ${WRKDIR}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
