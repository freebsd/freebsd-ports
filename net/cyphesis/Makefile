# New ports collection makefile for:	cyphesis
# Date created:				02 Oct 2005
# Whom:					Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cyphesis
PORTVERSION=	0.5.20
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/worldforge/${PORTNAME}%20%28server%29/${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A server for WorldForge games

LIB_DEPENDS=	Atlas-0.6.1:${PORTSDIR}/devel/atlas-devel \
		varconf-1.0.6:${PORTSDIR}/devel/varconf \
		wfmath-0.3.4:${PORTSDIR}/math/wfmath \
		mercator-0.2.6:${PORTSDIR}/devel/mercator \
		skstream-0.3.4:${PORTSDIR}/net/skstream \
		gcrypt.16:${PORTSDIR}/security/libgcrypt

CONFIGURE_ARGS=	--with-python=${LOCALBASE}

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_PGSQL=	yes
USE_PYTHON=	yes

CFLAGS+=	-I${LOCALBASE}/include

MAN1=		cyclient.1 cycmd.1 cyphesis.1 cyphesis-tools.1 cyaddrules.1 \
		cyconvertrules.1 cydumprules.1 cyloadrules.1 cypasswd.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's| install-dist_docDATA | |g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's| install-confbackupDATA | |g' ${WRKSRC}/data/Makefile.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
			  -e 's|-lpython|${PTHREAD_LIBS} &|' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -e 's|$$(datadir)/cyphesis|${DATADIR}|g'
	@${REINPLACE_CMD} -e 's|/bash|/sh|' ${WRKSRC}/scripts/extract_revision.sh
	@${REINPLACE_CMD} -e '1s|python|${LOCALBASE}/bin/${PYTHON_VERSION}|' ${WRKSRC}/scripts/gen_buildid.py

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/conf
.for docfile in README COPYING AUTHORS THANKS NEWS ChangeLog TODO
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.for docfile in acorn.xml basic.xml cyphesis.vconf mason.xml werewolf.xml
	@${INSTALL_DATA} ${WRKSRC}/data/${docfile} ${DOCSDIR}/conf
.endfor
.endif

.include <bsd.port.post.mk>
