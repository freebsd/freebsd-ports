# Created by: Vladimir Kondratiev <wulf@mail.mipt.ru>
# $FreeBSD$

PORTNAME=	cyrus2dovecot
PORTVERSION=	1.2
CATEGORIES=	mail
MASTER_SITES=	http://www.cyrus2dovecot.sw.fu-berlin.de/download/
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	wulf@mail.mipt.ru
COMMENT=	Convert Cyrus folders to Dovecot

PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

USE_PERL5=	yes
NO_WRKSUBDIR=	yes

post-extract:
	@${CP} -v ${DISTDIR}/${DISTNAME} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e '1s,^#!.*,#!${PERL},' ${WRKSRC}/${DISTNAME}

do-build:
	pod2man --section=1 --release=${PORTVERSION} \
		--name=${PORTNAME} --center=${PORTNAME}" user guide" \
		${WRKSRC}/${DISTNAME} ${WRKSRC}/${PORTNAME}.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${PREFIX}/man/man1/${PORTNAME}.1

.include <bsd.port.mk>
