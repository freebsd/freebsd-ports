# New ports collection makefile for:	soothsayer
# Date created:		7 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	soothsayer
PORTVERSION=	0.6.3
CATEGORIES=	textproc
MASTER_SITES=	# none known, please fix

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Intelligent predictive text entry platform

BUILD_DEPENDS=	help2man:${PORTSDIR}/misc/help2man

USE_GNOME=	pkgconfig
USE_SQLITE=	3
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		ac_cv_path_CPPUNIT_CONFIG=no \
		ac_cv_path_PYTHON=no \
		ac_cv_path_SWIG=no \
		ac_cv_prog_HAVE_DOT=no \
		ac_cv_prog_HAVE_DOXYGEN=no
CONFIGURE_ARGS=	--disable-python-binding
USE_LDCONFIG=	yes

MAN1=		soothsayer_demo.1 soothsayer_demo_text.1 \
		soothsayer_simulator.1 text2ngram.1

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

PORT_VERBS=	${PORTNAME} text2ngram

post-patch:
	@${REINPLACE_CMD} -e 's|\$$\^|$${.ALLSRC}| ; \
		 s|lib/soothsayer|soothsayer|g' ${WRKSRC}/resources/Makefile.in
	@${REINPLACE_CMD} -e 's|lib/soothsayer|soothsayer|' \
		${WRKSRC}/resources/profiles/Makefile.in
	@${REINPLACE_CMD} -e '1s|/.*|/bin/sh|'\
		${WRKSRC}/resources/profiles/generate_soothsayer_config.sh
	@${REINPLACE_CMD} -E -e "s|(LIBS=.*)-lsqlite3(.*)|\1\`pkg-config --static --libs sqlite3\`\2|" \
		-e "s|(.*SQLITE_LIBS=.*)-lsqlite3(.*)|\1\`pkg-config --static --libs sqlite3\`\2|" \
		${WRKSRC}/configure

.include <bsd.port.mk>
