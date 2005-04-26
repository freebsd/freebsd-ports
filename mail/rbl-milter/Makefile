# New ports collection makefile for:   rbl-milter
# Date created:        15 November 2002
# Whom:                wolpert
#
# $FreeBSD$
#

PORTNAME=	rbl-milter
PORTVERSION=	0.30
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://opensource.confusticate.com/rbl-milter/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A milter that adds mail header warnings on mail from open-relays

SUB_FILES=	rbl-milter.sh
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-sendmail=/usr \
		--with-sendmail-obj=/usr/lib

PLIST_FILES=	sbin/rbl-milter etc/rc.d/rbl-milter.sh

.if defined(NO_WERROR)
pre-configure:
	@${CP} ${WRKSRC}/configure ${WRKSRC}/configure.sed
	@${SED} 's!-Werror!!' ${WRKSRC}/configure.sed >${WRKSRC}/configure
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/rbl-milter.sh \
		${PREFIX}/etc/rc.d/rbl-milter.sh
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
