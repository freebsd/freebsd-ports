# New ports collection makefile for:   WiLiKi
# Date created:                22 August 2003
# Whom:                        Kimura Fuyuki <fuyuki@nigredo.org>
#
# $FreeBSD$
#

PORTNAME=	wiliki
PORTVERSION=	0.4
CATEGORIES=	www scheme
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	WiLiKi-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	fuyuki@nigredo.org
COMMENT=	A lightweight Wiki engine written in Scheme

BUILD_DEPENDS=	gosh:${PORTSDIR}/lang/gauche
RUN_DEPENDS=	${LOCALBASE}/share/gauche/${GAUCHE_VER}/lib/dbm/gdbm.scm:${PORTSDIR}/databases/gauche-gdbm

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "alpha"
BROKEN=		"Does not build"
.endif

.if exists(${LOCALBASE}/bin/gauche-config)
GAUCHE_VER!=	gauche-config -V
.else
GAUCHE_VER=	none
.endif

post-patch:
	${REINPLACE_CMD} -e 's,/usr/bin,${PREFIX}/bin,' \
		-e 's,/home/shiro/data/wikidata.dbm,/var/wiliki/data.dbm,' \
		-e 's/"wiliki-sample.css"/#f/' \
		-e "s/:language 'jp/:language 'en/" ${WRKSRC}/src/wiliki.cgi

pre-install:
	${MKDIR} `gauche-config --sitelibdir`

post-install:
	${MKDIR} ${PREFIX}/www/cgi-bin
	${INSTALL_DATA} ${WRKSRC}/src/wiliki.cgi \
		${PREFIX}/www/cgi-bin/wiliki.cgi.dist
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/wiliki-sample.css ${EXAMPLESDIR}
	${MKDIR} /var/wiliki
	${CHOWN} www:www /var/wiliki
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
