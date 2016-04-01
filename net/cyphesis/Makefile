# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cyphesis
PORTVERSION=	0.6.2
PORTREVISION=	6
CATEGORIES=	net
MASTER_SITES=	SF/worldforge/${PORTNAME}%20%28server%29/${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Server for WorldForge games

LICENSE=	GPLv2

LIB_DEPENDS=	libAtlas-0.6.so:devel/atlas-devel \
		libvarconf-1.0.so:devel/varconf \
		libwfmath-1.0.so:math/wfmath \
		libmercator-0.3.so:devel/mercator \
		libskstream-0.3.so:net/skstream \
		libgcrypt.so:security/libgcrypt \
		libboost_regex.so:devel/boost-libs

CONFIGURE_ARGS=	--with-python=${LOCALBASE}

GNU_CONFIGURE=	yes
USES=		gmake pathfix pkgconfig compiler:c++11-lib tar:bzip2 \
		python:2 pgsql
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
BROKEN=		Does not compile on FreeBSD 10+
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| install-dist_docDATA | |g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's| install-confbackupDATA | |g' \
		${WRKSRC}/data/minimal/Makefile.in \
		${WRKSRC}/data/mars/Makefile.in \
		${WRKSRC}/data/Makefile.in
	@${REINPLACE_CMD} -e 's|-lpython|-lpthread &|' \
		${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -e 's|$$(datadir)/cyphesis|${DATADIR}|g ; \
		s|confbackupdir = .*|confbackupdir = ${DOCSDIR}/conf|g'
	@${REINPLACE_CMD} -e 's|/bash|/sh|' ${WRKSRC}/scripts/extract_revision.sh
	@${REINPLACE_CMD} -e '1s|python|${LOCALBASE}/bin/${PYTHON_VERSION}|' ${WRKSRC}/scripts/gen_buildid.py
	@${REINPLACE_CMD} -e 's/#ifdef __APPLE__/#if defined(__APPLE__) || defined(__FreeBSD__)/g; \
		s/#ifndef __APPLE__/#if !defined(__APPLE__) \&\& !defined(__FreeBSD__)/g' \
		${WRKSRC}/common/system.cpp \
		${WRKSRC}/server/CommUnixListener.cpp

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/conf
.for file in README COPYING AUTHORS THANKS NEWS ChangeLog TODO FIXME
	@${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
.for xmlfile in acorn.xml basic.xml cyphesis.vconf mason.xml werewolf.xml
	@${INSTALL_DATA} ${WRKSRC}/data/${xmlfile} ${STAGEDIR}${DOCSDIR}/conf
.endfor

.include <bsd.port.post.mk>
