# Created by: shanee@augusta.de
# $FreeBSD$

PORTNAME=	logsurfer+
PORTVERSION=	1.7
CATEGORIES=	misc
MASTER_SITES=	http://kerryt.orconhosting.net.nz/ \
		http://www.crypt.gen.nz/logsurfer/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Process logfiles and conditionally perform certain actions

LICENSE=	BSD

SUB_FILES=	pkg-message
EXAMPLE_FILES=	context_arg_test.conf echo_test.conf \
		lines_test.conf syslog_test.conf

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-etcdir=${ETCDIR}

MAN1=		logsurfer.1
MAN4=		logsurfer.conf.4

NO_STAGE=	yes
post-install:
	@${MKDIR} ${ETCDIR}
.for conf in ${EXAMPLE_FILES}
	${INSTALL_DATA} ${WRKSRC}/config-examples/${conf} ${ETCDIR}/${conf}.sample
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
