# New ports collection makefile for:   rbl-milter
# Date created:        15 November 2002
# Whom:                wolpert
#
# $FreeBSD$
#

PORTNAME=	rbl-milter
PORTVERSION=	0.30
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://opensource.confusticate.com/rbl-milter/

MAINTAINER=	wolpert@codeheadsystems.com
COMMENT=	A milter that adds mail header warnings on mail from open-relays

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS=	--with-sendmail=/usr \
		--with-sendmail-obj=/usr/lib

.if defined(NO_WERROR)
pre-configure:
	@${CP} ${WRKSRC}/configure ${WRKSRC}/configure.sed
	@${SED} 's!-Werror!!' ${WRKSRC}/configure.sed >${WRKSRC}/configure
.endif

post-install:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' \
		${FILESDIR}/rbl-milter.sh.in > ${WRKDIR}/rbl-milter.sh
	${INSTALL_SCRIPT} ${WRKDIR}/rbl-milter.sh \
		${PREFIX}/etc/rc.d/rbl-milter.sh
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
