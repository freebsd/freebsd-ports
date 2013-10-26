# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cyphesis
PORTVERSION=	0.6.0
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	SF/worldforge/${PORTNAME}%20%28server%29/${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Server for WorldForge games

LIB_DEPENDS=	Atlas-0.6.1:${PORTSDIR}/devel/atlas-devel \
		varconf-1.0.8:${PORTSDIR}/devel/varconf \
		wfmath-1.0.1:${PORTSDIR}/math/wfmath \
		mercator-0.3.3:${PORTSDIR}/devel/mercator \
		skstream-0.3.7:${PORTSDIR}/net/skstream \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		boost_regex:${PORTSDIR}/devel/boost-libs

CONFIGURE_ARGS=	--with-python=${LOCALBASE}

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USES=		gmake pathfix pkgconfig
USE_LDCONFIG=	yes
USE_PGSQL=	yes
USE_PYTHON=	-2.7
USE_GCC=	4.7+

CFLAGS+=	-I${LOCALBASE}/include

MAN1=		cyclient.1 cycmd.1 cyphesis.1 cyphesis-tools.1 cyaddrules.1 \
		cyconvertrules.1 cydumprules.1 cyloadrules.1 cypasswd.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's| install-dist_docDATA | |g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's| install-confbackupDATA | |g' \
		${WRKSRC}/data/minimal/Makefile.in \
		${WRKSRC}/data/mars/Makefile.in \
		${WRKSRC}/data/Makefile.in
	@${REINPLACE_CMD} -e 's|-lpython|${PTHREAD_LIBS} &|' \
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
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/conf
.for docfile in README COPYING AUTHORS THANKS NEWS ChangeLog TODO FIXME
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.for docfile in acorn.xml basic.xml cyphesis.vconf mason.xml werewolf.xml
	@${INSTALL_DATA} ${WRKSRC}/data/${docfile} ${DOCSDIR}/conf
.endfor
.endif

.include <bsd.port.mk>
