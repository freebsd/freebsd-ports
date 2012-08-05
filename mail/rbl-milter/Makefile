# New ports collection makefile for:   rbl-milter
# Date created:        15 November 2002
# Whom:                wolpert
#
# $FreeBSD$
#

PORTNAME=	rbl-milter
PORTVERSION=	0.30
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://opensource.confusticate.com/rbl-milter/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A milter that adds mail header warnings on mail from open-relays

USE_RC_SUBR=	rblmilter
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" PTHREAD_LIBS="${PTHREAD_LIBS}"

PLIST_FILES=	sbin/rbl-milter

.if defined(NO_WERROR)
pre-configure:
	@${CP} ${WRKSRC}/configure ${WRKSRC}/configure.sed
	@${SED} 's!-Werror!!' ${WRKSRC}/configure.sed >${WRKSRC}/configure
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

CONFIGURE_ARGS+=	--with-sendmail=${MILTERBASE} \
			--with-sendmail-obj=${MILTERBASE}/lib

.include <bsd.port.post.mk>
