PORTNAME=	oidentd
DISTVERSION=	2.5.1
CATEGORIES=	security
MASTER_SITES=	https://files.janikrabe.com/pub/oidentd/releases/${DISTVERSION}/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Ident server that supports user-defined ident strings

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		bison tar:xz
USE_RC_SUBR=	oidentd
GNU_CONFIGURE=	yes

PLIST_FILES=	sbin/oidentd etc/oidentd.conf.sample \
		etc/oidentd_masq.conf.sample
MANPAGES=	oidentd.conf.5 oidentd_masq.conf.5 oidentd.8
.for man in ${MANPAGES}
PLIST_FILES+=	man/man${man:E}/${man}.gz
.endfor

CONFIGURE_ARGS=	--disable-masq

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/oidentd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${FILESDIR}/oidentd.conf.sample ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${FILESDIR}/oidentd_masq.conf.sample ${STAGEDIR}${PREFIX}/etc
.for MANFILE in ${MANPAGES}
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/doc/${MANFILE}
	${INSTALL_MAN} ${WRKSRC}/doc/${MANFILE} ${STAGEDIR}${PREFIX}/man/man${MANFILE:E}
.endfor

.include <bsd.port.mk>
