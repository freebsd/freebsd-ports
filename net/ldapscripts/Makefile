PORTNAME=	ldapscripts
PORTVERSION=	2.0.8
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		http://contribs.martymac.org/ldapscripts/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Scripts to manage posix accounts in an OpenLDAP directory
WWW=		https://contribs.martymac.org

LICENSE=	GPLv2

NO_ARCH=	yes

OPTIONS_DEFINE=	SASL DOCS

USES=		iconv ldap tar:tgz
LIBDIR=	${PREFIX}/lib/${PORTNAME}
MAKE_ENV+=	ETCDIR=${ETCDIR}

SUB_FILES=	pkg-message

PORTDOCS=	README CHANGELOG VERSION TODO

# Unset 'all' target set by default to 'help'
# and set paths to OpenLDAP binaries
post-patch:
	${REINPLACE_CMD} "s|^all:.*|all:|g" ${WRKSRC}/Makefile
	${REINPLACE_CMD} "s|^PREFIX = .*|PREFIX = ${PREFIX}|g ; \
		s|MANDIR =.*|MANDIR ?= ${PREFIX}/share/man|g" ${WRKSRC}/Makefile
	${REINPLACE_CMD} \
	-e "s|^LDAPSEARCHBIN=.*|LDAPSEARCHBIN=\"${LOCALBASE}/bin/ldapsearch\"|g" \
	-e "s|^LDAPADDBIN=.*|LDAPADDBIN=\"${LOCALBASE}/bin/ldapadd\"|g" \
	-e "s|^LDAPDELETEBIN=.*|LDAPDELETEBIN=\"${LOCALBASE}/bin/ldapdelete\"|g" \
	-e "s|^LDAPMODIFYBIN=.*|LDAPMODIFYBIN=\"${LOCALBASE}/bin/ldapmodify\"|g" \
	-e "s|^LDAPMODRDNBIN=.*|LDAPMODRDNBIN=\"${LOCALBASE}/bin/ldapmodrdn\"|g" \
	-e "s|^LDAPPASSWDBIN=.*|LDAPPASSWDBIN=\"${LOCALBASE}/bin/ldappasswd\"|g" \
	-e "s|^ICONVBIN=.*|ICONVBIN=\"${LOCALBASE}/bin/iconv\"|g" \
	${WRKSRC}/etc/ldapscripts.conf

# Install remaining stuff
post-install:
	@${RM} ${STAGEDIR}${ETCDIR}/ldapscripts.conf \
		${STAGEDIR}${ETCDIR}/ldapscripts.passwd
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
