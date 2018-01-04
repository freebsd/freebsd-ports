# Created by: Janos Mohacsi <janos.mohacsi@bsd.hu>
# $FreeBSD$

PORTNAME=	flowd
PORTVERSION=	0.9.1
PORTREVISION=	3
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	http://www2.mindrot.org/files/flowd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small, fast, and secure NetFlow collector

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	PERL PYTHON
OPTIONS_DEFAULT=PERL

PERL_DESC=	Install flowd perl module
PYTHON_DESC=	Install flowd Python support

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var
USE_RC_SUBR=	flowd
PORTDOCS=	README INSTALL
FLOWD_USER=	_flowd
USERS=		${FLOWD_USER}
GROUPS=		${FLOWD_USER}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPERL}
USES+=		perl5
USE_PERL5+=	build run
.endif

.if ${PORT_OPTIONS:MPYTHON}
USES+=		python:2.7
PLIST_SUB+=	PYTHON_VER=${PYTHON_VER}
.endif

post-patch:
	@${REINPLACE_CMD} -e "s;%%FLOWD_USER%%;${FLOWD_USER};g" \
		${WRKSRC}/flowd.h
	${REINPLACE_CMD} -i '' -e 's|/usr/bin/perl|${PERL}|' \
		${WRKSRC}/tools/flowinsert.pl \
		${WRKSRC}/tools/wormsuspects.pl

post-build:
.if ${PORT_OPTIONS:MPERL}
	(cd ${WRKSRC}/Flowd-perl && ${PERL} Makefile.PL \
		INSTALLSITEMAN3DIR=${PERL5_MAN3} \
		DESTDIR=${STAGEDIR} PREFIX=${PREFIX} && \
		${MAKE_CMD})
.endif

.if ${PORT_OPTIONS:MPYTHON}
	( cd ${WRKSRC} && ${PYTHON_CMD} setup.py build )
.endif

pre-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	( cd ${WRKSRC}/tools && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} )

.if ${PORT_OPTIONS:MPERL}
	( cd ${WRKSRC}/Flowd-perl && ${MAKE_CMD} install )
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Flowd/Flowd.so
.endif

.if ${PORT_OPTIONS:MPYTHON}
	( cd ${WRKSRC} && ${PYTHON_CMD} setup.py install --root "${STAGEDIR}" )
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/flowd.so
.endif

.include <bsd.port.mk>
