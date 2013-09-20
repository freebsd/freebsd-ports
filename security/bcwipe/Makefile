# Created by: crow
# $FreeBSD$

PORTNAME=	bcwipe
PORTVERSION=	1.9.8
CATEGORIES=	security
MASTER_SITES=	http://www.jetico.com/linux/ \
		http://bsd.desa-hosting.de/distfiles/security/
DISTNAME=	BCWipe-${PORTVERSION:S/./-/g:S/-/./}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	BCWipe securely erases data from magnetic and solid-state memory

NO_CDROM=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/./-/g:S/-/./}
GNU_CONFIGURE=  yes
MAKE_ARGS+=	CFLAGS="${CFLAGS}"

MAN1=		bcwipe.1
PLIST_FILES=	bin/bcwipe

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s,fprintf(stderr\,string),fprintf(stderr\,\"%s\"\,string),g" ${WRKSRC}/wipe.c
	@${REINPLACE_CMD} -e "s,if (NULL == mktemp(result)),if (mkstemp(result) == -1),g" ${WRKSRC}/wipe.c
	@${REINPLACE_CMD} -e "s,mktemp,mkstemp,g" ${WRKSRC}/wipe.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bcwipe ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/bcwipe.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
