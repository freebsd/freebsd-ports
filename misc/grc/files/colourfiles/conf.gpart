# Disk and Partition
regexp=((?:nvd|ada|da)\d+)(p\d+)?(.eli)?
colors=default,bright_cyan,bright_yellow,"\033[38;5;242m"
======
# ACTIVE
regexp=(ACTIVE|OK)
colors=unchanged,bright_green
======
# CORRUPT
regexp=(CORRUPT)
colors=unchanged,"\033[41m"
======
# Disk and Partition
regexp=(\w+\d+)(p\d+)$
colors=default,bright_cyan,bright_yellow
======
# Header
regexp=(\w+):
colors=default,"\033[38;5;242m"
======
# Header
regexp=(Name|Status|Components|State|EncryptionAlgorithm|KeyLength|Crypto|Flags|Mediasize|label|type)
colors=default,bright_white
======
# Providers | Consumers
regexp=(Geom name):
colors=default,bright_blue
======
# Providers | Consumers
regexp=(Providers|Consumers):
colors=default,bright_magenta
======
# Size
regexp=\((\d+(?:\.\d+)?G)\)
colors=default,"\033[38;5;214m"
======
# Size
regexp=\((\d+(?:\.\d+)?M)\)
colors=default,"\033[38;5;221m"
======
# Size
regexp=\((\d+(?:\.\d+)?K)\)
colors=default,"\033[38;5;223m"
======
regexp=(GPT|gpt)
colors=default,bright_green
======
regexp=(efi)
colors=default,bright_blue
======
regexp=(freebsd)-(?:(boot)|(swap)|(zfs)|(ufs))
colors=default,bright_cyan,bright_white,"\033[38;5;62m",bright_magenta,bright_green
======
regexp=(linux)-(?:(data|swap))
colors=default,yellow,green,red
======
