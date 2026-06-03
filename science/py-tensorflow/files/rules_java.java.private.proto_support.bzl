# Compatibility stub for rules_java 7.x + protobuf 6.31.1 (which needs 8.x APIs).

def compile(**kwargs):
    return java_common.compile(**kwargs)

def merge(providers, **kwargs):
    return java_common.merge(providers, **kwargs)
