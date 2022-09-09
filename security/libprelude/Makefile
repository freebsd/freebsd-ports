PORTNAME=	libprelude
PORTVERSION=	5.2.0
CATEGORIES=	security
MASTER_SITES=	https://www.prelude-siem.org/attachments/download/1395/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Sensor support library from Prelude SIEM
WWW=		https://www.prelude-siem.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libltdl.so:devel/libltdl \
		libpcre.so:devel/pcre

USES=		libtool localbase pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-lua \
		--without-python3 \
		--without-swig \
		--without-valgrind \
		ac_cv_path_RUBY=

INSTALL_TARGET=	install-strip

ETCDIR=		${PREFIX}/etc/prelude

OPTIONS_DEFINE=	DOCS PERL
OPTIONS_SUB=	yes

PERL_USES=		perl5
PERL_CONFIGURE_WITH=	perl=${PERL}

post-install:
.for f in client.conf global.conf idmef-client.conf tls.conf
	${MV} ${STAGEDIR}${ETCDIR}/default/${f} \
		${STAGEDIR}${ETCDIR}/default/${f}.sample
.endfor

.include <bsd.port.mk>
