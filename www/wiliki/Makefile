# New ports collection makefile for:   WiLiKi
# Date created:                22 August 2003
# Whom:                        Kimura Fuyuki <fuyuki@nigredo.org>
#
# $FreeBSD$
#

PORTNAME=	wiliki
PORTVERSION=	0.5
CATEGORIES=	www scheme
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	WiLiKi-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A lightweight Wiki engine written in Scheme

BUILD_DEPENDS=	gosh:${PORTSDIR}/lang/gauche
RUN_DEPENDS=	${LOCALBASE}/share/gauche/${GAUCHE_VER}/lib/dbm/gdbm.scm:${PORTSDIR}/databases/gauche-gdbm

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"Does not build"
.endif

.if exists(${LOCALBASE}/bin/gauche-config)
GAUCHE_VER!=	${LOCALBASE}/bin/gauche-config -V
.else
GAUCHE_VER=	none
.endif

post-patch:
	${REINPLACE_CMD} -E \
		-e 's,/usr/bin,${PREFIX}/bin,' \
		-e 's,/home/shiro/data/wikidata.dbm,/var/wiliki/data.dbm,' \
		-e 's,wiliki2?\.css,/&,' \
		-e "s/:language 'jp/:language 'en/" ${WRKSRC}/src/*.cgi

post-install:
	${MKDIR} ${PREFIX}/www/cgi-bin
.for f in wiliki.cgi wiliki2.cgi
	${INSTALL_DATA} ${WRKSRC}/src/${f} ${PREFIX}/www/cgi-bin/${f}.dist
.endfor
	${MKDIR} ${PREFIX}/www/data
	${INSTALL_DATA} ${WRKSRC}/src/*.css ${PREFIX}/www/data
	${MKDIR} /var/wiliki
	${CHOWN} www:www /var/wiliki
	@${CAT} ${PKGMESSAGE}

test:
	cd ${WRKSRC}; ${MAKE} check

.include <bsd.port.post.mk>
