# Created by: roam@FreeBSD.org
# $FreeBSD$

PORTNAME=	safecat
PORTVERSION=	1.13
CATEGORIES=	sysutils mail
MASTER_SITES=	http://www.jeenyus.net/linux/software/safecat/ \
		LOCAL/roam/sysutils/safecat \
		http://people.FreeBSD.org/~roam/ports/sysutils/safecat/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Safely write data to maildir directory

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

ALL_TARGET=	it
INSTALL_TARGET=	setup check
MAKE_JOBS_UNSAFE=yes

MAN1=		maildir.1 safecat.1
PLIST_FILES=	bin/maildir bin/safecat

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s,/usr/local,${PREFIX}," ${WRKSRC}/conf-root
	@${REINPLACE_CMD} -e "s,cc -O2,${CC} ${CFLAGS}," ${WRKSRC}/conf-cc
	@${REINPLACE_CMD} -e "s,cc -s,${CC} ${CFLAGS} ${STRIP}," ${WRKSRC}/conf-ld
	@${REINPLACE_CMD} 's|void main|int main|' \
		${WRKSRC}/install.c ${WRKSRC}/auto-str.c

.include <bsd.port.mk>
