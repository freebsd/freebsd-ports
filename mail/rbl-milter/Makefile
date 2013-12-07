# Created by: wolpert
# $FreeBSD$

PORTNAME=	rbl-milter
PORTVERSION=	0.30
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://opensource.confusticate.com/rbl-milter/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A milter that adds mail header warnings on mail from open-relays

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" PTHREAD_LIBS="${PTHREAD_LIBS}"

USE_RC_SUBR=	rblmilter
PLIST_FILES=	sbin/rbl-milter

.if defined(NO_WERROR)
pre-configure:
	${REINPLACE_CMD} -e 's!-Werror!!' ${WRKSRC}/configure
.endif

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

CONFIGURE_ARGS+=	--with-sendmail=${MILTERBASE} \
			--with-sendmail-obj=${MILTERBASE}/lib

.include <bsd.port.post.mk>
