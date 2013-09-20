# Created by: dm
# $FreeBSD$

PORTNAME=	avenger
PORTVERSION=	0.8.3
CATEGORIES=	mail
MASTER_SITES=	http://www.mailavenger.org/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Anti-spam SMTP server

GNU_CONFIGURE=	yes
USE_BDB=	43

USERS=		${PORTNAME}
GROUPS=		${USERS}

PORTDOCS=	INSTALL INSTALL.html README NEWS
SUB_FILES=	pkg-message

MAN1=		aliascheck.1 avenger.1 dbutil.1 deliver.1 dotlock.1 \
		edinplace.1 escape.1 macutil.1 mailexec.1 match.1 \
		smtpdcheck.1 synos.1
MAN5=		asmtpd.conf.5
MAN8=		asmtpd.8 avenger.local.8

CONFIGURE_ENV=	WFLAGS='-Wall'
CONFIGURE_ARGS=	--with-db=${LOCALBASE} --with-etcdir=${ETCDIR}

OPTIONS_DEFINE=	SASL

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSASL}
LIB_DEPENDS+=		sasl2:${PORTSDIR}/security/cyrus-sasl2
CONFIGURE_ARGS+=	--enable-sasl
.endif

post-install:
	${MKDIR} ${ETCDIR}
.for file in asmtpd.conf unknown
	${INSTALL_DATA} ${WRKSRC}/etc/${file} ${ETCDIR}/${file}.sample
	@if [ ! -f ${ETCDIR}/${file} ]; then \
		${CP} -p ${ETCDIR}/${file}.sample ${ETCDIR}/${file} ; \
	fi
.endfor
	${INSTALL_DATA} ${WRKSRC}/etc/pf.os ${PREFIX}/share
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/etc/smtp-filter.pf ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/etc/avsendmail.m4 ${DATADIR}

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
