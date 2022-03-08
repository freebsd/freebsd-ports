# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>

PORTNAME=	libprelude
PORTVERSION=	1.2.6
CATEGORIES=	security
MASTER_SITES=	http://www.prelude-siem.org/attachments/download/410/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Sensor support library from Prelude SIEM

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_riscv64=		fails to configure: Easybindings require a C++ compiler, but none were found.
DEPRECATED=	Very outdated, current version in tree was released back in 2015 and upstream is still active
EXPIRATION_DATE=2022-03-31

LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libgnutls.so:security/gnutls \
		libgcrypt.so:security/libgcrypt

OPTIONS_DEFINE=	DOCS PERL
OPTIONS_SUB=	yes

USES=		charsetfix gettext-runtime gmake iconv libtool pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-lua \
		--without-python3 \
		--without-swig \
		--without-valgrind \
		ac_cv_path_RUBY=
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

ETCDIR=		${PREFIX}/etc/prelude

PERL_CONFIGURE_WITH=	perl=${PERL}
PERL_USES=		perl5

post-install:
.for f in client.conf global.conf idmef-client.conf tls.conf
	${MV} ${STAGEDIR}${ETCDIR}/default/${f} \
		${STAGEDIR}${ETCDIR}/default/${f}.sample
.endfor

.include <bsd.port.mk>
