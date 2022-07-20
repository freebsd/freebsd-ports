PKGNAMESUFFIX=		-exim4

COMMENT=		mailman with Exim4 configuration and dependency

CONFLICTS_INSTALL=	mailman*postfix* mailman-2* mailman-with-htdig-2*

OPTIONS_EXCLUDE=	COURIER OPENSMTPD POSTFIX SENDMAIL
OPTIONS_SLAVE=		EXIM4

MASTERDIR=		${.CURDIR}/../../mail/mailman

.include "${MASTERDIR}/Makefile"
