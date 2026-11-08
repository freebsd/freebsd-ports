PORTNAME=	oidentd
DISTVERSION=	3.1.0
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${DISTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Ident server that supports user-defined ident strings
WWW=		https://sourceforge.net/projects/oidentd/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		bison tar:xz
USE_RC_SUBR=	oidentd
GNU_CONFIGURE=	yes

MANPAGES=	oidentd.conf.5 oidentd.8

CONFIGURE_ARGS=	--disable-masq

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/oidentd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${FILESDIR}/oidentd.conf.sample ${STAGEDIR}${PREFIX}/etc
.for MANFILE in ${MANPAGES}
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/doc/${MANFILE}
	${INSTALL_MAN} ${WRKSRC}/doc/${MANFILE} ${STAGEDIR}${PREFIX}/share/man/man${MANFILE:E}
.endfor

.include <bsd.port.mk>
